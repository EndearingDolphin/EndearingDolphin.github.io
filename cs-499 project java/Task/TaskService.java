/*
 * Name: Justin Fifarek
 * Course: SNHU CS-320
 * Date: 11/24/2023
 * 
 * Module 4-1 Milestone - Task service class
 */

package Task;
import java.util.ArrayList;

public class TaskService {
	// Array list to hold tasks
	public ArrayList<Task> taskList = new ArrayList<Task>();
	
	// Display tasks
	public void displayTasks() {
		for (int i = 0; i < taskList.size(); i++) {
			System.out.println("Task ID:  " + taskList.get(i).getTaskID());
			System.out.println("Task Name: " + taskList.get(i).getTaskName());
			System.out.println("Task Description: " + taskList.get(i).getTaskName());
		}
	}
	
	// Returns task given a taskID
	// Returns default task if no matching taskID is found
	public Task getTask(String taskID) {
		Task task = new Task(null, null);
		for (int i = 0; i < taskList.size(); i++) {
			if (taskList.get(i).getTaskID().contentEquals(taskID)) {
				task = taskList.get(i);
			}
		}
		return task;
	}
	
	// Adds new task
	public void addTask(String taskName, String taskDesc) {
		Task task = new Task(taskName, taskDesc);
		taskList.add(task);
	}
	
	// Delete task given a taskID
	public void deleteTask(String taskID) {
		for (int i = 0; i < taskList.size(); i++) {
			if (taskList.get(i).getTaskID().equals(taskID)) {
				taskList.remove(i);
				break;
			}
			if (i == taskList.size() - 1) {
				System.out.println("Task ID \'" + taskID + "' not found.");
			}
		}
	}
	
	// Update given taskID's taskName with given string
	public void updateTaskName(String newTaskName, String taskID) {
		for (int i = 0; i < taskList.size(); i++) {
			if (taskList.get(i).getTaskID().equals(taskID)) {
				taskList.get(i).setTaskName(newTaskName);
				break;
			}
			if (i == taskList.size() - 1) {
				System.out.println("Task ID: " + taskID + " not found.");
			}
		}
	}
	
	// Update given taskID's taskDesc with given string
	public void updateTaskDesc(String newTaskDesc, String taskID) {
		for (int i = 0; i < taskList.size(); i++) {
			if (taskList.get(i).getTaskID().equals(taskID)) {
				taskList.get(i).setTaskDesc(newTaskDesc);
				break;
			}
			if (i == taskList.size() - 1) {
				System.out.println("Task ID: " + taskID + " not found.");
			}
		}
	}
}