import React from "react";
import TodoList from "../components/TodoList";

function WeeklyTodo({ todos }) {
    const today = new Date();
    const startOfWeek = today.setDate(today.getDate() - today.getDay());
    const endOfWeek = today.setDate(today.getDate() + (6 - today.getDay()));

    const weeklyTodos = todos.filter(
        (todo) =>
            todo.date &&
            new Date(todo.date) >= new Date(startOfWeek) &&
            new Date(todo.date) <= new Date(endOfWeek)
    );

    return (
        <div>
            <h2>Weekly To-Do List</h2>
            <TodoList todos={weeklyTodos} />
        </div>
    );
}

export default WeeklyTodo;
