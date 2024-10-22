import React from 'react';

export const TodoList = ({ tasks, editTask, deleteTask }) => {
    return (
        <div className="todo-list max-w-4xl mx-auto">
            <h2 className="text-2xl font-semibold text-gray-700 mb-4">Your To-Do List</h2>
            {tasks.length === 0 ? (
                <p>No tasks available.</p>
            ) : (
                tasks.map((task) => (
                    <div key={task.id} className="todo-item">
                        <h3>{task.name}</h3>
                        <p><strong>Due:</strong> {task.date}</p>
                        <p>{task.description}</p>
                        <p><strong>Priority:</strong> {task.priority}</p>
                        <div>
                            <button onClick={() => editTask(task.id, task)}>Edit</button>
                            <button onClick={() => deleteTask(task.id)}>Delete</button>
                        </div>
                    </div>
                ))
            )}
        </div>
    );
};

