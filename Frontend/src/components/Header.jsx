import './Header.css'
import carbonImg from '../assets/carbon-footprint.png'
import { Link } from "react-router-dom";

export default function Header() {
    return (
        <header className='header-container'>
            <img src={carbonImg} alt="Carbon footprint"/>
            <h1>Carbon Footprint Calculator</h1>
            <p>
                In a world where sustainability matters more than ever,
                our app empowers you to measure and understand your personal
                carbon impact effortlessly. Join us in the journey towards a
                greener future as we guide you to make sustainable choices that 
                align with your lifestyle. 
            </p>
            <Link to="/credentials">
                <button>Go to Credentials Page</button>
            </Link>
        </header>
    );
}