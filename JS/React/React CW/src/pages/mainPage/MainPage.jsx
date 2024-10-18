import Navbar from "../../components/Navbar";
import FunctionComponent from "../../components/FunctionComponent";
import ClassComponent from "../../components/ClassComponents";
import { Box } from "@mui/material";
import { useState } from "react";
import "./MainPage.css";

function MainPage() {
    const [imageWidth, setImageWidth] = useState(400);

    const buttonStyle = {
        margin: "10px 20px",
        fontSize: "1.2em"
    };

    const imageStyle = {
        float: "left",
        marginRight: "20px"
    };
    

    function increseImageHandler() {
        const value = parseInt(document.getElementById("imageFactor").value);        
        setImageWidth(imageWidth + value)
    }

    function decreseImageHandler() {
        const value = parseInt(document.getElementById("imageFactor").value);                
        setImageWidth(imageWidth - value)
    }

    function resetImageHandler() {
        setImageWidth(400)
    }

    return (
        <>
            <div style={{margin: "10px"}}>
                <img
                    style={imageStyle}
                    width={`${imageWidth}px`}
                    src="https://i.pinimg.com/originals/5c/7b/53/5c7b53a7be1dd267f24f7559584d1345.jpg?r=523256"
                    alt=""
                />
                <span className="main-text">
                    React (старі назви: React.js, ReactJS) — відкрита JavaScript бібліотека для створення інтерфейсів користувача, яка покликана вирішувати проблеми часткового оновлення вмісту вебсторінки, з якими стикаються в розробці односторінкових застосунків. Розробляється Meta (раніше Facebook) і спільнотою індивідуальних розробників.
                </span>
                <span className="main-text">
                    React дозволяє розробникам створювати великі вебзастосунки, які використовують дані, котрі змінюються з часом, без перезавантаження сторінки. Його мета полягає в тому, щоб бути швидким, простим, масштабованим. React обробляє тільки користувацький інтерфейс у застосунках. Це відповідає видові у шаблоні модель-вид-контролер (MVC), і може бути використане у поєднанні з іншими JavaScript бібліотеками або в великих фреймворках MVC, таких як AngularJS. Він також може бути використаний з React на основі надбудов, щоб піклуватися про частини без користувацького інтерфейсу побудови вебзастосунків. Як бібліотеку інтерфейсу користувача React найчастіше використовують разом з іншими бібліотеками, такими як Redux.
                </span>
                <span className="main-text">
                    Бібліотеку створено Джорданом Волком (Jordan Walke), програмістом з Facebook. Автор працював над проектом під впливом XHP, фреймворку HTML для PHP.[13] 2011-го року реліз з'явився у новинах Facebook, за рік — у блозі Instagram.[14] Також фреймворк був представлений як проект з відкритим початковим кодом на конференції розробників JSConf US, що проходила у Сполучених Штатах у травні 2013 року. На конференції React.js Conf, влаштовану Фейсбуком у березні 2015-го, проект було представлено як відкрите програмне забезпечення.
                </span>
            </div>
            <div style={{textAlign: "center"}}>
                <button onClick={() => resetImageHandler()} style={buttonStyle}>Reset</button>
                <button onClick={() => increseImageHandler()} style={buttonStyle}>Increse</button>
                <button onClick={() => decreseImageHandler()} style={buttonStyle}>Decrese</button>
                <input id="imageFactor" type="number" min={0} max={100} />
            </div>
        </>
    );
}

export default MainPage;
