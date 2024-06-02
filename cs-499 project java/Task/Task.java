/*
 * Name: Justin Fifarek
 * Course: SNHU CS-320
 * Date: 11/24/2023
 * 
 * Module 4-1 Milestone - Task class
 */

package Task;
import java.util.concurrent.atomic.AtomicLong;

public class Task {
	// Private variables for task information
	private final String taskID;
	private String taskName;
	private String taskDesc;
	private static AtomicLong idGenerator = new AtomicLong();
	
	// Constructor
	public Task(String taskName, String taskDesc) {
		// TaskID is generated when constructor is called
		// with a final variable, therefore it cannot be changed.
		this.taskID = String.valueOf(idGenerator.getAndIncrement());
		
		// taskName cannot be more than 20 characters
		// and cannot be null
		if (taskName == null || taskName.isEmpty()) {
			this.taskName = "NULL";
		}
		else if (taskName.length() > 20) {
			this.taskName = taskName.substring(0, 20);
		}
		else {
			this.taskName = taskName;
		}
		
		// taskDesc cannot be more than 50 characters
		// and cannot be null
		if (taskDesc == null || taskDesc.isEmpty()) {
			this.taskDesc = "NULL";
		}
		else if (taskDesc.length() > 50) {
			this.taskDesc = taskDesc.substring(0, 50);
		}
		else {
			this.taskDesc = taskDesc;
		}
	}
	
	// Getters
	public String getTaskID() {
		return this.taskID;
	}
	public String getTaskName() {
		return this.taskName;
	}
	public String getTaskDesc() {
		return this.taskDesc;
	}
	
	// Setters
	// Set up variables with the same
	// conditions as the constructor.
	public void setTaskName(String taskName) {
		if (taskName == null || taskName.isEmpty()) {
			this.taskName = "NULL";
		}
		else if (taskName.length() > 20) {
			this.taskName = taskName.substring(0, 10);
		}
		else {
			this.taskName = taskName;
		}
	}
	
	public void setTaskDesc(String taskDesc) {
		if (taskDesc == null || taskDesc.isEmpty()) {
			this.taskDesc = "NULL";
		}
		else if (taskDesc.length() > 50) {
			this.taskDesc = taskDesc.substring(0, 50);
		}
		else {
			this.taskDesc = taskDesc;
		}
	}
	
}