import { useNavigate } from "react-router-dom";
import Header from "./components/Header";
import MainTopics from "./components/MainTopics";
import './components/QuestionFormatting.css';

function App() {
    const navigate = useNavigate();

    const handleCalculateClick = () => {
        // Navigate to the /calculate route
        navigate("/calculate");
        window.scrollTo(0, 0);
    };
    return(
        
        <>
            <Header />
            <main>
                <MainTopics />
                <div className="mainPageButton">
                    <button onClick={handleCalculateClick}>Calculate your Carbon Footprint</button>
                </div>
            </main>
        </>
        
    );
}

export default App;