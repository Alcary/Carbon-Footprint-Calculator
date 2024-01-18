import { BrowserRouter as Router, Route, Routes } from "react-router-dom";
import Calculate from "../components/Calculate";
import App from "../App";
import { useState, useEffect } from "react";
import Credentials from "../components/Credentials";

function Routing () {
    const [userId, setUserId] = useState(0);
    useEffect(() => {
        fetch('http://localhost:18080/createuser').then(res => res.json()).then(data => {
            setUserId(data);
        });
        window.scrollTo(0, 0);
    }, []);
    return (
        <Router>
            <Routes>
                <Route path="/" element={<App />} />
                <Route path="/calculate" element={<Calculate userId={userId} />} />
                <Route path="/credentials" element={<Credentials />} />
            </Routes>
        </Router>
    );

};

export default Routing;