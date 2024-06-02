/*
 * Name: Justin Fifarek
 * Course: SNHU CS-320
 * Date: 12/01/2023
 * 
 * Module 5-1 Milestone - Appointment class test
 */

package Test;

import static org.junit.jupiter.api.Assertions.*;
import java.util.Date;
import java.util.Calendar;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import Appointment.Appointment;

class AppointmentTest {
	private Date Date(int i, int january, int x) {
		return null;
	}
	
	@Test
	@DisplayName("Appointment ID cannot have more than 10 characters")
	void testAppointmentIDLength() {
		Appointment appointment = new Appointment(Date(2024, Calendar.JANUARY, 1), "Description");
		if (appointment.getAppointmentID().length() > 10) {
			fail("Appointment ID has more than 10 characters.");
		}
	}
	
	@Test
	@DisplayName("Task Description cannot have more than 50 characters")
	void testAppointmentDescLength() {
		Appointment appointment = new Appointment(Date(2022, Calendar.JANUARY, 1), "123456789 is nine characters long" 
				+ "123456789 is another nine characters long" 
				+ "123456789 is another nine characters long"
				+ "123456789 is another nine characters long");
		if (appointment.getAppointmentDesc().length() > 50) {
			fail("Appointment Description has more than 50 characters.");
		}
	}
	
	@Test
	@DisplayName("Appointment Date cannot be before current date")
	void testAppointmentDateBeforeCurrent() {
		Appointment appointment = new Appointment(Date(1022, Calendar.JANUARY, 1), "Description");
		if (appointment.getAppointmentDate().before(new Date())) {
			fail("Appointment Date is before current date.");
		}
	}

	@Test
	@DisplayName("Task Date shall not be null")
	void testAppointmentDateNotNull() {
		Appointment appointment = new Appointment(null, "Description");
		assertNotNull(appointment.getAppointmentDate(), "Appointment Date was null.");
	}
	
	@Test
	@DisplayName("Task Description shall not be null")
	void testAppointmentDescNotNull() {
		Appointment task = new Appointment(Date(2022, Calendar.JANUARY, 1), "Example description");
		assertNotNull(task.getAppointmentDesc(), "Appointment Description was null.");
	}
}

