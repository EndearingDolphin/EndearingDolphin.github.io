/*
 * Name: Justin Fifarek
 * Course: SNHU CS-320
 * Date: 12/01/2023
 * 
 * Module 5-1 Milestone - Appointment Service class test
 */

package Test;

import static org.junit.jupiter.api.Assertions.*;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Order;
import org.junit.jupiter.api.Test;

import Appointment.Appointment;
import Appointment.AppointmentService;

class AppointmentServiceTest {
	
	private Date Date(int i, int january, int j) {
		return null;
	}
	
	@Test
	@DisplayName("Test that service updates date properly")
	@Order(1)
	void testUpdateAppointmentDate() {
		AppointmentService service = new AppointmentService();
		service.addAppointment(Date(2024, Calendar.JANUARY, 1), "Example description");
		service.updateAppointmentDate(new Date(), "7");
		//service.displayApptList();
		assertEquals(new Date(), service.getAppointment("7").getAppointmentDate(), "Appointment date was not updated.");
	}

	@Test
	@DisplayName("Test that service updates description properly.")
	@Order(2)
	void testUpdateAppointmentDesc() {
		AppointmentService service = new AppointmentService();
		service.addAppointment(Date(2024, Calendar.JANUARY, 1), "Example description");
		service.updateAppointmentDesc("Updated Description", "9");
		//service.displayApptList();
		assertEquals("Updated Description", service.getAppointment("9").getAppointmentDesc(), "Appointment description was not updated.");
	}

	@Test
	@DisplayName("Test that service deletes appointments properly.")
	@Order(3)
	void testDeleteAppointment() {
		AppointmentService service = new AppointmentService();
		service.addAppointment(Date(2024, Calendar.JANUARY, 1), "Example description");
		service.deleteAppointment("11");
		ArrayList<Appointment> emptyAppointmentList = new ArrayList<Appointment>();
		//service.displayApptList();
		assertEquals(service.appointmentList, emptyAppointmentList, "The appointment was not deleted.");
	}

	@Test
	@DisplayName("Test that service adds appointments properly.")
	@Order(4)
	void testAddAppointment() {
		AppointmentService service = new AppointmentService();
		service.addAppointment(Date(2024, Calendar.JANUARY, 1), "Example description");
		//service.displayApptList();
		assertNotNull(service.getAppointment("1"), "Appointment was not added correctly.");
	}
}