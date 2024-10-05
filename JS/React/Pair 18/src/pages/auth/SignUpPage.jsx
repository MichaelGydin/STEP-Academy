import React from "react";
import { GoogleLogin, GoogleOAuthProvider } from "@react-oauth/google";

function SignUpPage() {
  const handleGoogleLogin = (credentialResponse) => {
  };

  return (
    <GoogleOAuthProvider clientId={"278128869750-b378q4m0u7688iu45budlt7u5nbt2bb1.apps.googleusercontent.com"}>
      <GoogleLogin
        onSuccess={handleGoogleLogin}
        onError={() => {
          console.log("Login Failed");
        }}
      />
    </GoogleOAuthProvider>
  );
}

export default SignUpPage;