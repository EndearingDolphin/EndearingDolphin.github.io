/*
 * Name: Justin Fifarek
 * Course: SNHU CS-320
 * Date: 11/16/2023
 * 
 * Module 3-2 Milestone - Contact class
 */

package Contact;

import java.util.concurrent.atomic.AtomicLong;

public class Contact {
	// Private variables for contact information.
	private final String contactID;
	private String firstName;
	private String lastName;
	private String phone;
	private String address;
	private static AtomicLong idGenerator = new AtomicLong();
	
	public Contact(String firstName, String lastName, String phone, String address) {
		// contactID is generated when constructor is called
		this.contactID = String.valueOf(idGenerator.getAndIncrement());
		
		// firstName cannot be more than 10 characters
		// and cannot be null
		if (firstName == null || firstName.isEmpty()) {
			this.firstName = "NULL";
		}
		else if (firstName.length() > 10) {
			this.firstName = firstName.substring(0, 10);
		}
		else {
			this.firstName = firstName;
		}
		
		// lastName cannot be more than 10 characters
		// and cannot be null
		if (lastName == null || lastName.isEmpty()) {
			this.lastName = "NULL";
		}
		else if (lastName.length() > 10) {
			this.lastName = lastName.substring(0, 10);
		}
		else {
			this.lastName = lastName;
		}
		
		// phone must be exactly 10 digits
		// and cannot be null
		if (phone == null || phone.isEmpty()) {
			this.phone = "1234567890";
		}
		else if (phone.length() > 10) {
			this.phone = phone.substring(0, 10);
		}
		else {
			this.phone = phone;
		}
		
		// address cannot be more than 30 characters
		// and cannot be null
		if (address == null || address.isEmpty()) {
			this.address = "NULL";
		}
		else if (address.length() > 30) {
			this.address = address.substring(0, 30);
		}
		else {
			this.address = address;
		}
	}
	
	// Getters
	public String getContactID() {
		return contactID;
	}
	public String getFirstName() {
		return this.firstName;
	}
	public String getLastName() {
		return this.lastName;
	}
	public String getPhone() {
		return this.phone;
	}
	public String getAddress() {
		return this.address;
	}
	
	// Setters
	// Set up the same as in constructor
	public void setFirstName(String firstName) {
		if (firstName == null || firstName.isEmpty()) {
			this.firstName = "NULL";
		}
		else if (firstName.length() > 10) {
			this.firstName = firstName.substring(0, 10);
		}
		else {
			this.firstName = firstName;
		}
	}
	
	public void setLastName(String lastName) {
		if (lastName == null || lastName.isEmpty()) {
			this.lastName = "NULL";
		}
		else if (lastName.length() > 10) {
			this.lastName = lastName.substring(0, 10);
		}
		else {
			this.lastName = lastName;
		}
	}
	
	public void setPhone(String phone) {
		if (phone == null || phone.isEmpty()) {
			this.phone = "1234567890";
		}
		else if (phone.length() > 10) {
			this.phone = phone.substring(0, 10);
		}
		else {
			this.phone = phone;
		}
	}
	
	public void setAddress(String address) {
		if (address == null || address.isEmpty()) {
			this.address = "NULL";
		}
		else if (address.length() > 30) {
			this.address = address.substring(0, 30);
		}
		else {
			this.address = address;
		}
	}
}