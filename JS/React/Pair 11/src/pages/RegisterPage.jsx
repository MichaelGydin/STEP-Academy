import React from 'react';
import './Auth.css';

function RegisterPage() {
  return (
    <div className="page">
      <form>
        <h1>Register</h1>
        <input type="register-text" placeholder="Username" />
        <input type="register-password" placeholder="Password" />
        <input type="register-email" placeholder="Email" />
        <button type="register-submit">Register</button>
      </form>
    </div>
  );
}

export default RegisterPage;
