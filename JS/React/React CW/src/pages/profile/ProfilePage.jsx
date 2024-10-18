import React from "react";
import { useSelector } from "react-redux";

function ProfilePage() {
  const { user } = useSelector((store) => store.authReducer);

  return (
    <div>
      <h1>Профіль</h1>
      <img src={user.image} alt="User  Avatar" />
      <p>Ім'я: {user.firstName}</p>
      <p>Прізвище: {user.lastName}</p>
      <p>Пошта: {user.email}</p>
    </div>
  );
}

export default ProfilePage;