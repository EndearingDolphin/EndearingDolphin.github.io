/*
 * Name: Justin Fifarek
 * Course: SNHU CS-320
 * Date: 11/24/2023
 * 
 * Module 4-1 Milestone - Task service class test
 */

package Test;

import static org.junit.jupiter.api.Assertions.*;
import java.util.ArrayList;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Order;
import org.junit.jupiter.api.Test;
import Task.Task;
import Task.TaskService;

class TaskServiceTest {
	@Test
	@DisplayName("Test to Update task name")
	@Order(1)
	void testUpdateTaskName() {
		TaskService ts = new TaskService();
		ts.addTask("Task Name", "Description");
		ts.updateTaskName("Updated Task Name", "3");
		//ts.displayTasks();
		assertEquals("Updated Task Name", ts.getTask("3").getTaskName(), "Task name was not updated.");
	}

	@Test
	@DisplayName("Test to Update task description.")
	@Order(2)
	void testUpdateTaskDesc() {
		TaskService ts = new TaskService();
		ts.addTask("Task Name", "Description");
		ts.updateTaskDesc("Updated Description", "1");
		//ts.displayTasks();
		assertEquals("Updated Description", ts.getTask("1").getTaskDesc(), "Task description was not updated.");
	}

	@Test
	@DisplayName("Test to ensure that service can add a task.")
	@Order(3)
	void testAddContact() {
		TaskService ts = new TaskService();
		ts.addTask("Task Name", "Description");
		//ts.displayTasks();
		assertNotNull(ts.getTask("0"), "Task was not added correctly.");
	}
	
	@Test
	@DisplayName("Test to ensure that service correctly deletes tasks.")
	@Order(4)
	void testDeleteContact() {
		TaskService ts = new TaskService();
		ts.addTask("Task Name", "Description");
		ts.deleteTask("0");
		ArrayList<Task> taskListEmpty = new ArrayList<Task>();
		//ts.displayTasks();
		assertEquals(ts.taskList, taskListEmpty, "Task was not deleted.");
	}
}
