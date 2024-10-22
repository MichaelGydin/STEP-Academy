import React, { useState } from 'react';

export const TodoForm = ({ addTask }) => {
    const [task, setTask] = useState({
        name: '',
        description: '',
        date: '',
        priority: 'Normal',
        id: Date.now(),
    });

    const handleInputChange = (e) => {
        const { name, value } = e.target;
        setTask((prevTask) => ({
            ...prevTask,
            [name]: value,
        }));
    };

    const handleSubmit = (e) => {
        e.preventDefault();
        if (task.name.trim() === '') return;
        addTask(task);
        setTask({ name: '', description: '', date: '', priority: 'Normal', id: Date.now() });
    };

    return (
        <form onSubmit={handleSubmit} className="todo-form p-6 bg-white rounded-lg shadow-lg">
            <h2>Add New Task</h2>
            <div className="p-field">
                <label>Task Name</label>
                <input
                    type="text"
                    name="name"
                    value={task.name}
                    onChange={handleInputChange}
                    placeholder="Enter task name"
                    required
                />
            </div>
            <div className="p-field">
                <label>Task Description</label>
                <textarea
                    name="description"
                    value={task.description}
                    onChange={handleInputChange}
                    placeholder="Enter task description"
                />
            </div>
            <div className="p-field">
                <label>Due Date</label>
                <input
                    type="date"
                    name="date"
                    value={task.date}
                    onChange={handleInputChange}
                    required
                />
            </div>
            <div className="p-field">
                <label>Priority</label>
                <select
                    name="priority"
                    value={task.priority}
                    onChange={handleInputChange}
                >
                    <option value="Low">Low</option>
                    <option value="Normal">Normal</option>
                    <option value="High">High</option>
                </select>
            </div>
            <button type="submit" className="mt-4">Add Task</button>
        </form>
    );
};
