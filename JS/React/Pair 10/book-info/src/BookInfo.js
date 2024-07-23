import React from 'react';

function BookInfo() {
  return (
    <div>
      <h1>Назва книги: "Eloquent JavaScript"</h1>
      <p>Автор: Marijn Haverbeke</p>
      <p>Жанр: Програмування</p>
      <p>Кількість сторінок: 450</p>
      <div>
        <h2>Рецензії:</h2>
        <ul>
          <li>Ця книга є чудовим введенням у JavaScript.</li>
          <li>Дуже детально і зрозуміло описано.</li>
          <li>Рекомендую всім початківцям.</li>
        </ul>
      </div>
    </div>
  );
}

export default BookInfo;
