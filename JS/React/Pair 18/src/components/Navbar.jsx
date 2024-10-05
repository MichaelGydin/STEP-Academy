import React from "react";
import AppBar from "@mui/material/AppBar";
import Box from "@mui/material/Box";
import Toolbar from "@mui/material/Toolbar";
import IconButton from "@mui/material/IconButton";
import Typography from "@mui/material/Typography";
import Menu from "@mui/material/Menu";
import MenuIcon from "@mui/icons-material/Menu";
import Container from "@mui/material/Container";
import Button from "@mui/material/Button";
import MenuItem from "@mui/material/MenuItem";
import AdbIcon from "@mui/icons-material/Adb";
import { Link } from "react-router-dom";
import { useSelector } from "react-redux";
import { useAction } from "../hooks/useAction";
import DarkModeIcon from '@mui/icons-material/DarkMode';

const pages = [
  { id: 1, name: "Main", url: "/" },
  { id: 2, name: "News", url: "/news" },
  { id: 3, name: "Weather", url: "/weather" },
];

function Navbar() {
  const [anchorElNav, setAnchorElNav] = React.useState(null);

  // отримання даних зі store
  const { isAuth, user } = useSelector((store) => store.authReducer);
  const { logout, switchTheme } = useAction();

  const handleOpenNavMenu = (event) => {
    setAnchorElNav(event.currentTarget);
  };

  const handleCloseNavMenu = () => {
    setAnchorElNav(null);
  };

  const logoutHandler = () => {
    logout();
  };

  const switchThemeHandler = () => {
    switchTheme();
  };

  return (
    // mui: sx == style
    <AppBar position="static">
      <Container maxWidth="xl">
        <Toolbar disableGutters>
          <AdbIcon
            sx={{ display: { xs: "none", md: "flex" }, mr: 1 }}
          />
          <Typography
            variant="h6"
            noWrap
            component="a"
            href="#app-bar-with-responsive-menu"
            sx={{
              mr: 2,
              display: { xs: "none", md: "flex" },
              fontFamily: "monospace",
              fontWeight: 700,
              letterSpacing: ".3rem",
              color: "inherit",
              textDecoration: "none",
            }}
          >
            LOGO
          </Typography>

          <Box
            sx={{
              flexGrow: 1,
              display: { xs: "flex", md: "none" },
            }}
          >
            <IconButton
              size="large"
              aria-label="account of current user"
              aria-controls="menu-appbar"
              aria-haspopup="true"
              onClick={handleOpenNavMenu}
              color="inherit"
            >
              <MenuIcon />
            </IconButton>
            <Menu
              id="menu-appbar"
              anchorEl={anchorElNav}
              anchorOrigin={{
                vertical: "bottom",
                horizontal: "left",
              }}
              keepMounted
              transformOrigin={{
                vertical: "top",
                horizontal: "left",
              }}
              open={Boolean(anchorElNav)}
              onClose={handleCloseNavMenu}
              sx={{
                display: { xs: "block", md: "none" },
              }}
            >
              {pages.map((page) => (
                <Link to={page.url} key={page.id}>
                  <MenuItem onClick={handleCloseNavMenu}>
                    <Typography textAlign="center">
                      {page.name}
                    </Typography>
                  </MenuItem>
                </Link>
              ))}
            </Menu>
          </Box>
          <AdbIcon
            sx={{ display: { xs: "flex", md: "none" }, mr: 1 }}
          />
          <Typography
            variant="h5"
            noWrap
            component="a"
            href="#app-bar-with-responsive-menu"
            sx={{
              mr: 2,
              display: { xs: "flex", md: "none" },
              flexGrow: 1,
              fontFamily: "monospace",
              fontWeight: 700,
              letterSpacing: ".3rem",
              color: "inherit",
              textDecoration: "none",
            }}
          >
            LOGO
          </Typography>
          <Box
            sx={{
              flexGrow: 1,
              display: { xs: "none", md: "flex" },
            }}
          >
            {pages.map((page) => (
              <Link to={page.url} key={page.id}>
                <Button
                  onClick={handleCloseNavMenu}
                  sx={{
                    my: 2,
                    color: "white",
                    display: "block",
                  }}
                >
                  {page.name}
                </Button>
              </Link>
            ))}
          </Box>
          <DarkModeIcon onClick={switchThemeHandler } />
          {isAuth ? (
            <Box sx={{ display: "flex", alignItems: "center" }}>
              <Link to="/profile">
                {user && user.image ? (
                  <img
                    src={user.image}
                    alt="User  Avatar"
                    style={{
                      width: "40px",
                      height: "40px",
                      borderRadius: "50%",
                      marginRight: "10px",
                    }}
                  />
                ) : (
                  <Typography variant="h5">{user.email}</Typography>
                )}
              </Link>
              <Link to="/login">
                <Button
                    variant="contained"
                    color="error"
                    onClick={logoutHandler}
                >
                    Вийти
                </Button>
              </Link>
            </Box>
          ) : (
            <Box sx={{ display: "flex", alignItems: "center" }}>
              <Link to="/login">
                <Button variant="contained" color="success">
                  Увійти
                </Button>
              </Link>
              <Link to="/register">
                <Button variant="contained" color="success">
                  Реєстрація
                </Button>
              </Link>
            </Box>
          )}
        </Toolbar>
      </Container>
    </AppBar>
  );
}

export default Navbar;