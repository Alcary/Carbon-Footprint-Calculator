import { useState, useEffect } from "react";
import Transportation from "./Transportation";
import Household from "./Household";
import Food from "./Food";
import Results from "./Results";
import './QuestionFormatting.css';
import LoadingScreen from "./LoadingScreen";

const Calculate = (userId) => {
    const [index, setIndex] = useState(0);
    const [loading, setLoading] = useState(false);
    const boxes = [
        <Transportation onNext={() => handleNext(index + 1)} id={userId} />,
        <Household onNext={() => handleNext(index + 1)} id={userId} />,
        <Food onNext={() => handleNext(index + 1)} id={userId} />,
        <Results userId={userId}/>
    ];

    const handleNext = (nextIndex) => {
        setIndex(nextIndex);
    };

    useEffect(() => {
        console.log(userId);
        window.scrollTo(0, 0);
    }, [index]);

    return (
        <div>
            {loading ? (
                <LoadingScreen />
            ) : (
                    boxes[index]               
            )}
        </div>
    );
};

export default Calculate;