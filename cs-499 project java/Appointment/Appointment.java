/*
 * Name: Justin Fifarek
 * Course: SNHU CS-320
 * Date: 12/01/2023
 * 
 * Module 5-1 Milestone - Appointment class
 */

package Appointment;

import java.util.concurrent.atomic.AtomicLong;
import java.util.Calendar;
import java.util.Date;

public class Appointment {
	// Private variables for appointment information
	private final String appointmentID;
	private Date appointmentDate;
	private String appointmentDesc;
	private static AtomicLong idGenerator = new AtomicLong();
	
	@SuppressWarnings("deprecation")
	public Appointment(Date appointmentDate, String appointmentDesc) {
		// appointmentID is generated when constructor is called
		this.appointmentID = String.valueOf(idGenerator.getAndIncrement());
		
		// appointmentDate cannot be before the current date
		if (appointmentDate == null) {
			this.appointmentDate = new Date(2025, Calendar.JANUARY, 1);
		}
		else if (appointmentDate.before(new Date())) {
			throw new IllegalArgumentException("Invalid date. Date cannot be in the past.");
		}
		else {
			this.appointmentDate = appointmentDate;
		}
		
		// appointmentDesc cannot be more than 50 characters
		// and cannot be null
		if (appointmentDesc == null || appointmentDesc.isEmpty()) {
			this.appointmentDesc = appointmentDesc;
		}
		else if (appointmentDesc.length() > 50) {
			this.appointmentDesc = appointmentDesc.substring(0, 50);
		}
		else {
			this.appointmentDesc = appointmentDesc;
		}
	}
	
	// Getters
	public String getAppointmentID() {
		return this.appointmentID;
	}
	public Date getAppointmentDate() {
		return this.appointmentDate;
	}
	public String getAppointmentDesc() {
		return this.appointmentDesc;
	}
	
	// Setters
	// Set up the same as in constructor
	@SuppressWarnings("deprecation")
	public void setAppointmentDate(Date appointmentDate) {
		if (appointmentDate == null) {
			this.appointmentDate = new Date(2024, Calendar.JANUARY, 1);
		}
		else if (appointmentDate.before(new Date())) {
			throw new IllegalArgumentException("Invalid date. Date cannot be in the past.");
		}
		else {
			this.appointmentDate = appointmentDate;
		}
	}
	
	public void setAppointmentDesc(String appointmentDesc) {
		if (appointmentDesc == null || appointmentDesc.isEmpty()) {
			this.appointmentDesc = appointmentDesc;
		}
		else if (appointmentDesc.length() > 50) {
			this.appointmentDesc = appointmentDesc.substring(0, 50);
		}
		else {
			this.appointmentDesc = appointmentDesc;
		}
	}
}