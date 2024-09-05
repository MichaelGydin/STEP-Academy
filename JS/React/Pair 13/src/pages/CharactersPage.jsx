import { useState, useEffect } from "react";
import { Container, Grid, Pagination } from "@mui/material";
import Card from "@mui/material/Card";
import CardActions from "@mui/material/CardActions";
import CardContent from "@mui/material/CardContent";
import CardMedia from "@mui/material/CardMedia";
import Typography from "@mui/material/Typography";

function CharactersPage() {
    const [characters, setCharacters] = useState([]);
    const [currentPage, setCurrentPage] = useState(1);
    const charactersPerPage = 10;
    const apiUrl = "https://thronesapi.com/api/v2/Characters";

    useEffect(() => {
        fetch(apiUrl)
            .then((response) => response.json())
            .then((data) => {
                setCharacters(data);
            })
            .catch((error) => console.log(error));
    }, []);

    const indexOfLastCharacter = currentPage * charactersPerPage;
    const indexOfFirstCharacter = indexOfLastCharacter - charactersPerPage;
    const currentCharacters = characters.slice(indexOfFirstCharacter, indexOfLastCharacter);

    const handlePageChange = (event, value) => {
        setCurrentPage(value);
    };

    return (
        <Container>
            <h1>Game of Thrones Characters</h1>
            <Grid container gap={4}>
                {currentCharacters.map((character) => (
                    <Card key={character.id} sx={{ maxWidth: 345 }}>
                        <CardMedia
                            sx={{ height: 140 }}
                            image={character.imageUrl}
                            title={character.fullName}
                        />
                        <CardContent>
                            <Typography gutterBottom variant="h5" component="div">
                                {character.fullName}
                            </Typography>
                            <Typography variant="body2" color="text.secondary">
                                {character.title}
                            </Typography>
                        </CardContent>
                    </Card>
                ))}
            </Grid>
            <Pagination
                count={Math.ceil(characters.length / charactersPerPage)}
                page={currentPage}
                onChange={handlePageChange}
                color="primary"
                sx={{ mt: 4 }}
            />
        </Container>
    );
}

export default CharactersPage;
