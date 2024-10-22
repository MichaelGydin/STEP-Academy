import React from "react";
import TodoList from "../components/TodoList";

function MonthlyTodo({ todos }) {
    const thisMonth = new Date().getMonth();

    const monthlyTodos = todos.filter(
        (todo) => todo.date && new Date(todo.date).getMonth() === thisMonth
    );

    return (
        <div>
            <h2>Monthly To-Do List</h2>
            <TodoList todos={monthlyTodos} />
        </div>
    );
}

export default MonthlyTodo;
