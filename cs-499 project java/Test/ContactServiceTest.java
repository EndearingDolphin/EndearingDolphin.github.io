/*
 * Name: Justin Fifarek
 * Course: SNHU CS-320
 * Date: 11/16/2023
 * 
 * Module 3-2 Milestone - Contact Service class test
 */

package Test;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestMethodOrder;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.MethodOrderer.OrderAnnotation;
import org.junit.jupiter.api.Order;
import java.util.ArrayList;
import Contact.Contact;
import Contact.ContactService;

@TestMethodOrder(OrderAnnotation.class)
class ContactServiceTest {

	// Testing ContactService methods
	@Test
	@DisplayName("Add contact test")
	@Order(1)
	void test_AddContact() {
		ContactService cs = new ContactService();
		cs.addContact("John", "Smith", "1234567890", "12345 Avenue");
		cs.displayContacts();
		assertNotNull(cs.getContact("0"), "Contact was not added.");
	}
	
	@Test
	@DisplayName("Delete contact test")
	@Order(2)
	void test_DeleteContact() {
		ContactService cs = new ContactService();
		cs.addContact("John", "Smith", "1234567890", "12345 Avenue");
		cs.deleteContact("11");
		ArrayList<Contact> emptyContactList = new ArrayList<Contact>();
		cs.displayContacts();
		assertEquals(cs.contactList, emptyContactList, "Contact was not deleted.");
	}
	
	@Test
	@DisplayName("Update first name test")
	@Order(3)
	void test_UpdateFirstName() {
		ContactService cs = new ContactService();
		cs.addContact("John",  "Smith", "1234567890", "12345 Avenue");
		cs.updateFirstName("Jane", "12");
		cs.displayContacts();
		assertEquals("Jane", cs.getContact("12").getFirstName(), "First name was not updated.");
	}
	
	@Test
	@DisplayName("Update last name test")
	@Order(4)
	void test_UpdateLastName() {
		ContactService cs = new ContactService();
		cs.addContact("John",  "Smith", "1234567890", "12345 Avenue");
		cs.updateLastName("Doe", "14");
		cs.displayContacts();
		assertEquals("Doe", cs.getContact("14").getLastName(), "Last name was not updated.");
	}
	
	@Test
	@DisplayName("Update phone test")
	@Order(5)
	void test_UpdatePhone() {
		ContactService cs = new ContactService();
		cs.addContact("John",  "Smith", "1234567890", "12345 Avenue");
		cs.updatePhone("1111111111", "16");
		cs.displayContacts();
		assertEquals("1111111111", cs.getContact("16").getPhone(), "Phone was not updated.");
	}
	
	@Test
	@DisplayName("Update address test")
	@Order(5)
	void test_UpdateAddress() {
		ContactService cs = new ContactService();
		cs.addContact("John",  "Smith", "1234567890", "12345 Avenue");
		cs.updateAddress("Summer Street", "18");
		cs.displayContacts();
		assertEquals("Summer Street", cs.getContact("18").getAddress(), "Address was not updated.");
	}
	
	
}
