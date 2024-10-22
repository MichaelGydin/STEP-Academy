import React from "react";
import TodoList from "../components/TodoList";

function DailyTodo({ todos }) {
    const today = new Date().toDateString();
    const dailyTodos = todos.filter((todo) => todo.date && new Date(todo.date).toDateString() === today);

    return (
        <div>
            <h2>Daily To-Do List</h2>
            <TodoList todos={dailyTodos} />
        </div>
    );
}

export default DailyTodo;
