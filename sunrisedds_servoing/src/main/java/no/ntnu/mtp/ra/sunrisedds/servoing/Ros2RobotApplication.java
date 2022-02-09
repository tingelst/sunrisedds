package no.ntnu.mtp.ra.sunrisedds.servoing;

import org.apache.log4j.BasicConfigurator;

import com.kuka.common.ThreadUtil;
import com.kuka.connectivity.motionModel.smartServo.SmartServo;
import com.kuka.roboticsAPI.applicationModel.RoboticsAPIApplication;
import com.kuka.roboticsAPI.applicationModel.RoboticsAPIApplicationState;
import com.kuka.roboticsAPI.deviceModel.LBR;
import com.kuka.roboticsAPI.geometricModel.ObjectFrame;
import com.kuka.roboticsAPI.geometricModel.Tool;

import no.ntnu.mtp.ra.sunrisedds.SunriseDDS;
import no.ntnu.mtp.ra.sunrisedds.core.DDSException;
import no.ntnu.mtp.ra.sunrisedds.domain.DomainParticipant;
import no.ntnu.mtp.ra.sunrisedds.pub.Publisher;
import no.ntnu.mtp.ra.sunrisedds.pub.DataWriter;
import no.ntnu.mtp.ra.sunrisedds.topic.Topic;

import sensor_msgs.msg.JointState;

public class Ros2RobotApplication extends RoboticsAPIApplication {

    private LBR robot = null;
    private Tool tool = null;

    private SmartServo motion = null;

    private ObjectFrame toolFrame = null;
    private ObjectFrame endpointFrame = null;

    private boolean running = true;

    private DomainParticipant domainParticipant = null;
    private Publisher publisher = null;
    private Topic<JointState> topic;
    private DataWriter<JointState> writer = null;


    @Override
    public void initialize() {
    	
    	BasicConfigurator.configure();

        SunriseDDS.init();
        try {
            domainParticipant = SunriseDDS.createDomainParticipant();
            publisher = domainParticipant.createPublisher();
            topic = domainParticipant.createTopic(JointState.class, "rt/joint_states");
            writer = publisher.createDataWriter(topic);
              
        } catch (DDSException e) {
            e.printStackTrace();
        }

        robot = getContext().getDeviceFromType(LBR.class);

        toolFrame = robot.getFlange();
        endpointFrame = toolFrame;

        //endpointFrame.moveAsync(motion);

    }

    @Override
    public void run() throws Exception {
        while (running) {
        	
        	JointState msg = new JointState();
        	msg.getHeader().setFrameId("Lars");
        	
        	writer.write(msg);
        	
        	ThreadUtil.milliSleep(100);
        }
        getLogger().info("Stopping!");

    }

    @Override
    public void dispose() {
        try {
            SunriseDDS.delete(domainParticipant);
        } catch (DDSException e) {
            e.printStackTrace();
        }
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
