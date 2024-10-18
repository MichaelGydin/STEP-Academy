import React from "react";
import {
    Avatar,
    Grid,
    Box,
    Button,
    TextField,
    Container,
    Typography,
} from "@mui/material";
import LockOutlinedIcon from "@mui/icons-material/LockOutlined";
import { useFormik } from "formik";
import { Link, useNavigate } from "react-router-dom";
import * as Yup from "yup";
import { useAction } from "../../hooks/useAction";

function SignUpPage() {
  const navigate = useNavigate();
  const { register, signIn } = useAction();

  const validationSchema = Yup.object({
      username: Yup.string()
          .required("Поле обов'язкове"),
      email: Yup.string()
          .email("Невірний формат пошти")
          .required("Поле обов'язкове"),
      birthDate: Yup.date()
          .required("Поле обов'язкове")
          .max(new Date(), "Дата народження не може бути в майбутньому"),
      password: Yup.string()
          .min(8, "Пароль повинен містити мінімум 8 символів")
          .required("Поле обов'язкове"),
      confirmPassword: Yup.string()
          .oneOf([Yup.ref("password"), null], "Паролі не збігаються")
          .required("Поле обов'язкове"),
  });

  const submitHandler = async (values) => {
      // Виконати реєстрацію
      const registerSuccess = await register(values);
      if (registerSuccess) {
          // Логін після успішної реєстрації
          signIn({ email: values.email, password: values.password });
          navigate("/");
      }
  };

  const formik = useFormik({
      initialValues: {
          username: "",
          email: "",
          birthDate: "",
          password: "",
          confirmPassword: "",
      },
      onSubmit: submitHandler,
      validationSchema: validationSchema,
  });

  return (
      <Container component="main" maxWidth="xs">
          <div style={{ marginTop: "20px" }}>
              <Box>
                  <Avatar sx={{ margin: "auto" }}>
                      <LockOutlinedIcon />
                  </Avatar>
              </Box>
              <Typography
                  sx={{ textAlign: "center" }}
                  component="h1"
                  variant="h5"
              >
                  Реєстрація
              </Typography>
              <form noValidate onSubmit={formik.handleSubmit}>
                  <TextField
                      variant="outlined"
                      margin="normal"
                      required
                      fullWidth
                      id="username"
                      label="Логін"
                      name="username"
                      autoComplete="username"
                      autoFocus
                      value={formik.values.username}
                      onChange={formik.handleChange}
                      onBlur={formik.handleBlur}
                  />
                  {formik.touched.username && formik.errors.username ? (
                      <div style={{ color: "red" }}>
                          {formik.errors.username}
                      </div>
                  ) : null}

                  <TextField
                      variant="outlined"
                      margin="normal"
                      required
                      fullWidth
                      id="email"
                      label="Email Address"
                      name="email"
                      autoComplete="email"
                      value={formik.values.email}
                      onChange={formik.handleChange}
                      onBlur={formik.handleBlur}
                  />
                  {formik.touched.email && formik.errors.email ? (
                      <div style={{ color: "red" }}>
                          {formik.errors.email}
                      </div>
                  ) : null}

                  <TextField
                      variant="outlined"
                      margin="normal"
                      required
                      fullWidth
                      id="birthDate"
                      label="Дата народження"
                      name="birthDate"
                      type="date"
                      InputLabelProps={{
                          shrink: true,
                      }}
                      value={formik.values.birthDate}
                      onChange={formik.handleChange}
                      onBlur={formik.handleBlur}
                  />
                  {formik.touched.birthDate && formik.errors.birthDate ? (
                      <div style={{ color: "red" }}>
                          {formik.errors.birthDate}
                      </div>
                  ) : null}

                  <TextField
                      variant="outlined"
                      margin="normal"
                      required
                      fullWidth
                      name="password"
                      label="Пароль"
                      type="password"
                      id="password"
                      autoComplete="current-password"
                      value={formik.values.password}
                      onChange={formik.handleChange}
                      onBlur={formik.handleBlur}
                  />
                  {formik.touched.password && formik.errors.password ? (
                      <div style={{ color: "red" }}>
                          {formik.errors.password}
                      </div>
                  ) : null}

                  <TextField
                      variant="outlined"
                      margin="normal"
                      required
                      fullWidth
                      name="confirmPassword"
                      label="Підтвердження паролю"
                      type="password"
                      id="confirmPassword"
                      value={formik.values.confirmPassword}
                      onChange={formik.handleChange}
                      onBlur={formik.handleBlur}
                  />
                  {formik.touched.confirmPassword && formik.errors.confirmPassword ? (
                      <div style={{ color: "red" }}>
                          {formik.errors.confirmPassword}
                      </div>
                  ) : null}

                  <Button
                      disabled={!(formik.isValid && formik.dirty)}
                      type="submit"
                      fullWidth
                      variant="contained"
                      color="primary"
                  >
                      Зареєструватися
                  </Button>
                  <Grid container>
                      <Grid item>
                          <Link to="/signin">
                              {"Вже є обліковий запис? Увійти"}
                          </Link>
                      </Grid>
                  </Grid>
              </form>
          </div>
      </Container>
  );
}

export default SignUpPage;