import React, { useState, useEffect } from 'react';
import { TodoForm } from './components/TodoForm';
import { TodoList } from './components/TodoList';

function App() {
    const [tasks, setTasks] = useState([]);

    useEffect(() => {
        const savedTasks = JSON.parse(localStorage.getItem('tasks'));
        if (savedTasks) {
            setTasks(savedTasks);
        }
    }, []);

    const saveToLocalStorage = (updatedTasks) => {
        localStorage.setItem('tasks', JSON.stringify(updatedTasks));
    };

    const addTask = (task) => {
        const updatedTasks = [...tasks, task];
        setTasks(updatedTasks);
        saveToLocalStorage(updatedTasks);
    };

    const editTask = (taskId, updatedTask) => {
        const updatedTasks = tasks.map((task) =>
            task.id === taskId ? updatedTask : task
        );
        setTasks(updatedTasks);
        saveToLocalStorage(updatedTasks);
    };

    const deleteTask = (taskId) => {
        const updatedTasks = tasks.filter((task) => task.id !== taskId);
        setTasks(updatedTasks);
        saveToLocalStorage(updatedTasks);
    };

    return (
        <div className="container mx-auto p-4">
            <h1 className="text-3xl font-bold text-center mb-6">To-Do List App</h1>
            <TodoForm addTask={addTask} />
            <TodoList tasks={tasks} editTask={editTask} deleteTask={deleteTask} />
        </div>
    );
}

export default App;
