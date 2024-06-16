/*
 * Name: Justin Fifarek
 * Course: SNHU CS-320
 * Date: 11/16/2023
 * 
 * Module 3-2 Milestone - Contact Service class
 */

package Contact;

import java.util.ArrayList;

public class ContactService {
	// Array list to hold contacts
	public ArrayList<Contact> contactList = new ArrayList<Contact>();
	
	// Display list of stored contacts
	public void displayContacts() {
		for (int i = 0; i < contactList.size(); i++) {
			System.out.println(" Contact ID: " + contactList.get(i).getContactID());
			System.out.println(" First Name: " + contactList.get(i).getFirstName());
			System.out.println(" Last Name: " + contactList.get(i).getLastName());
			System.out.println(" Phone Number: " + contactList.get(i).getPhone());
			System.out.println(" Address: " + contactList.get(i).getAddress());
			for (int x = 0; x < contactList.get(i).getAddress().length() + 9; x++) {
				System.out.print("-");
			}
			System.out.println("");
		}
	}
	
	// Adds new contact using contact constructor
	public void addContact(String firstName, String lastName, String phone, String address) {
		Contact contact = new Contact(firstName, lastName, phone, address);
		contactList.add(contact);
	}
	
	// Searches through the array and returns contact information, given a contact ID
	// Returns a default contact if no matching ID is found
	public Contact getContact(String contactID) {
		Contact contact = new Contact(null, null, null, null);
		for (int i = 0; i < contactList.size(); i++) {
			if (contactList.get(i).getContactID().contentEquals(contactID)) {
				contact = contactList.get(i);
			}
		}
		return contact;
	}
	
	// Searches contact array given a contactID and deletes the entry
	public void deleteContact(String contactID) {
		for (int i = 0; i < contactList.size(); i++) {
			if (contactList.get(i).getContactID().equals(contactID)) {
				contactList.remove(i);
				break;
			}
			if (i == contactList.size() - 1) {
				System.out.println("Contact ID: " + contactID + " not found.");
			}
		}
	}
	
	// Updates contact firstName of given contactID with given string
	public void updateFirstName(String updatedString, String contactID) {
		for (int i = 0; i < contactList.size(); i++) {
			if (contactList.get(i).getContactID().equals(contactID)) {
				contactList.get(i).setFirstName(updatedString);
				break;
			}
			if (i == contactList.size() - 1) {
				System.out.println("Contact ID: " + contactID + " not found.");
			}
		}
	}
	
	// Updates contact lastName of given contactID with given string
	public void updateLastName(String updatedString, String contactID) {
		for (int i = 0; i < contactList.size(); i++) {
			if (contactList.get(i).getContactID().equals(contactID)) {
				contactList.get(i).setLastName(updatedString);
				break;
			}
			if (i == contactList.size() - 1) {
				System.out.println("Contact ID: " + contactID + " not found.");
			}
		}
	}
	
	// Updates contact phone number of given contactID with given string
	public void updatePhone(String updatedString, String contactID) {
		for (int i = 0; i < contactList.size(); i++) {
			if (contactList.get(i).getContactID().equals(contactID)) {
				contactList.get(i).setPhone(updatedString);
				break;
			}
			if (i == contactList.size() - 1) {
				System.out.println("Contact ID: " + contactID + " not found.");
			}
		}
	}
	
	// Updates contact address of given contactID with given string
	public void updateAddress(String updatedString, String contactID) {
		for (int i = 0; i < contactList.size(); i++) {
			if (contactList.get(i).getContactID().equals(contactID)) {
				contactList.get(i).setAddress(updatedString);
				break;
			}
			if (i == contactList.size() - 1) {
				System.out.println("Contact ID: " + contactID + " not found.");
			}
		}
	}
}
