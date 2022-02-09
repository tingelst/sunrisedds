package no.ntnu.mtp.ra.sunrisedds.servoing;

import java.util.concurrent.TimeUnit;

import com.kuka.connectivity.motionModel.smartServo.ISmartServoRuntime;
import com.kuka.connectivity.motionModel.smartServo.SmartServo;
import com.kuka.roboticsAPI.applicationModel.RoboticsAPIApplication;
import com.kuka.roboticsAPI.applicationModel.RoboticsAPIApplicationState;
import com.kuka.roboticsAPI.deviceModel.JointPosition;
import com.kuka.roboticsAPI.deviceModel.LBR;
import com.kuka.roboticsAPI.geometricModel.ObjectFrame;
import com.kuka.roboticsAPI.geometricModel.Tool;

import no.ntnu.mtp.ra.sunrisedds.SunriseDDS;
import no.ntnu.mtp.ra.sunrisedds.core.DDSException;
import no.ntnu.mtp.ra.sunrisedds.core.WaitSet;
import no.ntnu.mtp.ra.sunrisedds.domain.DomainParticipant;
import no.ntnu.mtp.ra.sunrisedds.pub.DataWriter;
import no.ntnu.mtp.ra.sunrisedds.pub.Publisher;
import no.ntnu.mtp.ra.sunrisedds.sub.DataReader;
import no.ntnu.mtp.ra.sunrisedds.sub.ReadCondition;
import no.ntnu.mtp.ra.sunrisedds.sub.Subscriber;
import no.ntnu.mtp.ra.sunrisedds.sub.Subscriber.DataState;
import no.ntnu.mtp.ra.sunrisedds.topic.Topic;

public class RobotApplication extends RoboticsAPIApplication {

    private LBR robot = null;
    private Tool tool = null;

    private SmartServo motion = null;
    private ISmartServoRuntime runtime = null;

    private ObjectFrame toolFrame = null;
    private ObjectFrame endpointFrame = null;

    private boolean running = true;

    double minTrajectoryExecutionTime = 0.1;
    double timeoutAfterGoalReach = 3600;

    private DomainParticipant domainParticipant = null;
    private Publisher publisher = null;
    private Subscriber subscriber = null;
    private Topic<sunrisedds_interfaces.msg.JointPosition> commandTopic = null;
    private DataReader<sunrisedds_interfaces.msg.JointPosition> commandReader = null;
    private ReadCondition<sunrisedds_interfaces.msg.JointPosition> commandReadCondition = null;
    private Topic<sunrisedds_interfaces.msg.JointPosition> stateTopic = null;
    private DataWriter<sunrisedds_interfaces.msg.JointPosition> stateWriter = null;

    @Override
    public void initialize() {

        try {
            SunriseDDS.init();

            domainParticipant = SunriseDDS.createDomainParticipant();

            publisher = domainParticipant.createPublisher();
            stateTopic = domainParticipant.createTopic(sunrisedds_interfaces.msg.JointPosition.class, "rt/state");
            stateWriter = publisher.createDataWriter(stateTopic);

            subscriber = domainParticipant.createSubscriber();
            commandTopic = domainParticipant.createTopic(sunrisedds_interfaces.msg.JointPosition.class, "rt/command");
            commandReader = subscriber.createDataReader(commandTopic);
            DataState dataState = subscriber.createDataState().withAnyState();
            commandReadCondition = commandReader.createReadCondition(dataState);


        } catch (DDSException e) {
            e.printStackTrace();
        }

        robot = getContext().getDeviceFromType(LBR.class);
    }

    @Override
    public void run() throws Exception {

        toolFrame = robot.getFlange();
        endpointFrame = toolFrame;

        motion = new SmartServo(robot.getCurrentJointPosition());
        endpointFrame.moveAsync(motion);

        runtime = motion.getRuntime();

        WaitSet waitSet = domainParticipant.createWaitSet();
        waitSet.attach(commandReadCondition);

        while (running) {

            runtime.updateWithRealtimeSystem();
            JointPosition actualPosition = runtime.getAxisQMsrOnController();

            sunrisedds_interfaces.msg.JointPosition stateMessage = new sunrisedds_interfaces.msg.JointPosition();
            stateMessage.getPosition().setA1(actualPosition.get(0));
            stateMessage.getPosition().setA2(actualPosition.get(1));
            stateMessage.getPosition().setA3(actualPosition.get(2));
            stateMessage.getPosition().setA4(actualPosition.get(3));
            stateMessage.getPosition().setA5(actualPosition.get(4));
            stateMessage.getPosition().setA6(actualPosition.get(5));
            stateMessage.getPosition().setA7(actualPosition.get(6));
            stateWriter.write(stateMessage);


            waitSet.waitForConditions(SunriseDDS.createDuration(100, TimeUnit.MILLISECONDS));
            sunrisedds_interfaces.msg.JointPosition commandMessage = commandReader.read();
 
            if (commandMessage != null) {

                // Convert to JointPosition and setDestination

            }





            

            



            JointPosition target = new JointPosition(robot.getJointCount());
            motion.getRuntime().setDestination(target);

            motion.getRuntime().getAxisQMsrOnController();
            motion.getRuntime().getFineIpoState();

        }

    }

    @Override
    public void dispose() {
        // TODO Auto-generated method stub
        super.dispose();
    }

    @Override
    public void onApplicationStateChanged(RoboticsAPIApplicationState state) {
        if (state == RoboticsAPIApplicationState.STOPPING) {
            running = false;
        }
        super.onApplicationStateChanged(state);
    }

}