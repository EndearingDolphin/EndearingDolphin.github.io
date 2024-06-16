/*
 * Name: Justin Fifarek
 * Course: SNHU CS-320
 * Date: 12/01/2023
 * 
 * Module 5-1 Milestone - Appointment Service class
 */

package Appointment;

import java.util.ArrayList;
import java.util.Date;

public class AppointmentService {
	// Array list to store appointments
	public ArrayList<Appointment> appointmentList = new ArrayList<Appointment>();
	
	// Display all appointments in the list
	public void displayApptList() {
		for (int i = 0; i < appointmentList.size(); i++) {
			System.out.println("Appointment ID: " + appointmentList.get(i).getAppointmentID());
			System.out.println("Appointment Date: " + appointmentList.get(i).getAppointmentDate());
			System.out.println("Appointment Description: " + appointmentList.get(i).getAppointmentDesc());
		}
	}
	
	// Adds a new appointment using the constructor 
	// and then adds to the appointment list
	public void addAppointment(Date appointmentDate, String appointmentDesc) {
		// Create the new appointment
		Appointment appointment = new Appointment(appointmentDate, appointmentDesc);
		appointmentList.add(appointment);
	}
	
	// Returns an appointment given appointmentID, if it exists. 
	// Otherwise, returns a default appointment
	public Appointment getAppointment(String appointmentID) {
		Appointment appointment = new Appointment(null, null);
		for (int i = 0; i < appointmentList.size(); i++) {
			if (appointmentList.get(i).getAppointmentID().contentEquals(appointmentID)) {
				appointment = appointmentList.get(i);
			}
		}
		return appointment;
	}
	
	// Loops through appointmentList for given appointmendID 
	// and deletes it if found.
	public void deleteAppointment(String appointmentID) {
		for (int i = 0; i < appointmentList.size(); i++) {
			if (appointmentList.get(i).getAppointmentID().equals(appointmentID)) {
				appointmentList.remove(i);
				break;
			}
			if (i == appointmentList.size() - 1) {
				System.out.println("Appointment ID: " + appointmentID + " not found.");
			}
		}
	}

	// Updates appointmentDate of appointmentID given a newDate
	public void updateAppointmentDate(Date newDate, String appointmentID) {
		for (int i = 0; i < appointmentList.size(); i++) {
			if (appointmentList.get(i).getAppointmentID().equals(appointmentID)) {
				appointmentList.get(i).setAppointmentDate(newDate);
				break;
			}
			if (i == appointmentList.size() - 1) {
				System.out.println("Appointment ID: " + appointmentID + " not found.");
			}
		}
	}

	// Updates appointmentDesc of given appointmendID
	public void updateAppointmentDesc(String newDesc, String appointmentID) {
		for (int i = 0; i < appointmentList.size(); i++) {
			if (appointmentList.get(i).getAppointmentID().equals(appointmentID)) {
				appointmentList.get(i).setAppointmentDesc(newDesc);
				break;
			}
			if (i == appointmentList.size() - 1) {
				System.out.println("Appointment ID: " + appointmentID + " not found.");
			}
		}
	}
}