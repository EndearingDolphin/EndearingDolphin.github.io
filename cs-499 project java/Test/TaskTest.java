/*
 * Name: Justin Fifarek
 * Course: SNHU CS-320
 * Date: 11/24/2023
 * 
 * Module 4-1 Milestone - Task class test
 */

package Test;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import Task.Task;

class TaskTest {

	@Test
	@DisplayName("Task Description shall not be null")
	void testTaskDescNotNull() {
		Task task = new Task("Name", null);
		assertNotNull(task.getTaskDesc(), "Task Description was null.");
	}
	
	@Test
	@DisplayName("Task Name shall not be null")
	void testTaskNameNotNull() {
		Task task = new Task(null, "Description");
		assertNotNull(task.getTaskName(), "Task Name was null.");
	}
	
	@Test
	@DisplayName("Task ID cannot have more than 10 characters")
	void testTaslIDLength() {
		Task task = new Task("Name", "Description");
		if (task.getTaskID().length() > 10) {
			fail("Task ID has more than 10 characters.");
		}
	}
	
	@Test
	@DisplayName("Task Name cannot have more than 20 characters")
	void testTaskNameLength() {
		Task task = new Task("OllyOllyOxenFreeOllyOllyOxenFree", "Description");
		if (task.getTaskName().length() > 20) {
			fail("Task Name has more than 20 characters.");
		}
	}
	
	@Test
	@DisplayName("Task Description cannot have more than 50 characters")
	void testTaskDescLength() {
		Task task = new Task("Name", "This sentence is 37 characters long.");
		if (task.getTaskDesc().length() > 50) {
			fail("Task Description has more than 50 characters.");
		}
	}
}
