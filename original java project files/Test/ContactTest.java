/*
 * Name: Justin Fifarek
 * Course: SNHU CS-320
 * Date: 11/16/2023
 * 
 * Module 3-2 Milestone - Contact class test
 */

package Test;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.DisplayName;
import Contact.Contact;

class ContactTest {
	
	
	// Because the constructor and setters are already set up to 
	// handle the length and whether a value is null,
	// these tests should all pass.
	
	
	// Testing for character length
	@Test
	@DisplayName("Contact ID cannot have more than 10 charaters.")
	void test_ContactIDMoreThan10Characters() {
		Contact contact = new Contact("firstName", "lastName", "phone", "address");
		if (contact.getContactID().length() > 10) {
			fail("Contact ID has more than 10 characters.");
		}
	}
	
	@Test
	@DisplayName("Contact first name cannot have more than 10 characters.")
	void test_ContactFirstNameMoreThan10Characters() {
		Contact contact = new Contact("This is a test for first name", "lastName", "phone", "address");
		if (contact.getFirstName().length() > 10) {
			fail("First name has more than 10 characters.");
		}
	}
	
	@Test
	@DisplayName("Contact last name cannot have more than 10 characters.")
	void test_ContactLastNameMoreThan10Characters() {
		Contact contact = new Contact("firstName", "This is a test for last name", "phone", "address");
		if (contact.getLastName().length() > 10) {
			fail("Last name has more than 10 characters.");
		}
	}
	
	@Test
	@DisplayName("Contact phone must be exactly 10 characters.")
	void test_ContactPhoneExactly10Characters() {
		Contact contact = new Contact("firstName", "lastName", "1234567890", "address");
		if (contact.getPhone().length() != 10) {
			fail("Phone is not exactly 10 characters.");
		}
	}
	
	@Test
	@DisplayName("Contact address cannot be longer than 30 characters")
	void test_ContactAddressMoreThan30Characters() {
		Contact contact = new Contact("firstName", "lastName", "phone", "address");
		if (contact.getAddress().length() > 30) {
			fail("Address has more than 30 characters.");
		}
	}
	
	
	// Testing for null
	@Test
	@DisplayName("Contact first name cannot be null.")
	void test_ContactFirstNameNull() {
		Contact contact = new Contact(null, "lastName", "phone", "address");
		assertNotNull(contact.getFirstName(), "First name is null.");
	}
	
	@Test
	@DisplayName("Contact last name cannot be null.")
	void test_ContactLastNameNull() {
		Contact contact = new Contact("lastName", null, "phone", "address");
		assertNotNull(contact.getFirstName(), "Last name is null.");
	}
	
	@Test
	@DisplayName("Contact phone is cannot be null.")
	void test_ContactPhoneNull() {
		Contact contact = new Contact("firstName", "lastName", null, "address");
		assertNotNull(contact.getPhone(), "Phone is null.");
	}
	
	@Test
	@DisplayName("Contact address cannot be null.")
	void test_ContactAddressNull() {
		Contact contact = new Contact("firstName", "lastName", "phone", null);
		assertNotNull(contact.getAddress(), "Address name is null.");
	}
}



