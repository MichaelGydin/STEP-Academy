import React from "react";
import {
    Avatar,
    Grid,
    Box,
    Button,
    TextField,
    FormControlLabel,
    Checkbox,
    Container,
    Typography,
} from "@mui/material";
import LockOutlinedIcon from "@mui/icons-material/LockOutlined";
import { useFormik } from "formik";
import { Link, useNavigate } from "react-router-dom";
import * as Yup from "yup";

function SignInPage() {
    const navigate = useNavigate();

    const initFormValues = {
        email: "",
        password: "",
    };

    const auth = localStorage.getItem("auth");
    if(auth != null) {
        const cred = JSON.parse(auth);

        initFormValues.email = cred.email;
        initFormValues.password = cred.password;
    }

    const validationSchema = Yup.object({
        // email
        email: Yup.string()
            .email("Невірний формат пошти")
            .required("Поле обов'язкове"),
        // password
        password: Yup.string()
            .min(6, "Пароль повинен містити мінімум 6 символів")
            .required("Поле обов'язкове"),
    });

    function submitHandler(values) {
        const json = JSON.stringify(values);
        localStorage.setItem("auth", json);
        navigate("/")
    }

    // create formik
    const formik = useFormik({
        initialValues: initFormValues,
        onSubmit: submitHandler,
        validationSchema: validationSchema
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
                    Логін
                </Typography>
                <form noValidate onSubmit={formik.handleSubmit}>
                    <TextField
                        variant="outlined"
                        margin="normal"
                        required
                        fullWidth
                        id="email"
                        label="Email Address"
                        name="email"
                        autoComplete="email"
                        autoFocus
                        value={formik.values.email}
                        onChange={formik.handleChange}
                        onBlur={formik.handleBlur}
                    />
                    {formik.touched.email && formik.errors.email ? (
                        <div style={{color: "red"}}>{formik.errors.email}</div>
                    ) : null}

                    <TextField
                        variant="outlined"
                        margin="normal"
                        required
                        fullWidth
                        name="password"
                        label="Password"
                        type="password"
                        id="password"
                        autoComplete="current-password"
                        value={formik.values.password}
                        onChange={formik.handleChange}
                        onBlur={formik.handleBlur}
                    />
                    {formik.touched.password && formik.errors.password ? (
                        <div style={{color: "red"}}>{formik.errors.password}</div>
                    ) : null}

                    <FormControlLabel
                        control={<Checkbox value="remember" color="primary" />}
                        label="Remember me"
                    />
                    <Button
                    // якщо поля не відповідють валідації то кнопка сабміт буде не активна
                        disabled={!(formik.isValid && formik.dirty)}
                        type="submit"
                        fullWidth
                        variant="contained"
                        color="primary"
                    >
                        Увійти
                    </Button>
                    <Grid container>
                        <Grid item>
                            <Link to="/register">
                                {"Don't have an account? Sign Up"}
                            </Link>
                        </Grid>
                    </Grid>
                </form>
            </div>
        </Container>
    );
}

export default SignInPage;
