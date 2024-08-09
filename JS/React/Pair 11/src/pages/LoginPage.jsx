import React from 'react';
import './Auth.css';

function LoginPage() {
  return (
    <div className="page">
      <form>
        <h1>Login</h1>
        <input type="login-text" placeholder="Username" />
        <input type="login-password" placeholder="Password" />
        <button type="login-submit">Login</button>
      </form>
    </div>
  );
}

export default LoginPage;