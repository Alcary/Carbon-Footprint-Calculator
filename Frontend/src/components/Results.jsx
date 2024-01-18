import { useNavigate } from "react-router-dom";
import { useEffect, useState } from "react";
import { Link } from "react-router-dom";
import resultlogo from '../assets/result.png'
import './Results.css'; // Import your CSS file

const Results = ({ userId }) => {
    const navigate = useNavigate();
    const [result, setResult] = useState(0);

    const handleBackToMain = () => {
        // Navigate to the main page
        navigate("/");
        window.scrollTo(0, 0);
    };

    useEffect(() => {
        console.log(userId);
        fetch(`http://localhost:18080/total?id=${userId.userId}`)
            .then((res) => res.json())
            .then((data) => {
                setResult(data.toFixed(2));
            })
            .catch((err) => {
                setResult("invalid params");
            });
        window.scrollTo(0, 0);
    }, []);

    let message = "";

    if (result == 0) {
        message = "Oops! It is too good to be true! You may have left all fields uncompleted.";
    } else if (result < 10) {
        message = "Congratulations! Your carbon footprint is low. Keep up the good work!";
    } else if (result >= 10) {
        message = "Oops! Your carbon footprint is relatively high. Consider ways to reduce it.";
    }

    return (
        <div className="results-container">
            <img src={resultlogo} alt=" Result Logo" className="logo" />
            <h2 className="title">Your results:</h2>
            <h2 className="results">{result} tonnes/year</h2>
            {message && <p className="message">{message}</p>}
            <button onClick={handleBackToMain}>Back to Main Page</button>
            <Link to="/credentials">
                <button>Go to Credentials Page</button>
            </Link>
        </div>
    );
};

export default Results;
