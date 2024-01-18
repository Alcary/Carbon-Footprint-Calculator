import { Link } from 'react-router-dom';
import erasmusolgo from '../assets/erasmuslogo.png';
import './CredFormatting.css';

const Credentials = () => {
    return (
        
        <div className='credentials-container'>
            <div className='logo-container'>
                <img src={erasmusolgo} alt="Erasmus Logo" className='erasmus-logo'/>
            </div>
            <div className='text-container'>
                <h1>Project title: Gender, Digitalization, Green: Ensuring a Sustainable Future for all in Europe</h1>
                <p>Coordinator teacher(s): Mihail Caramihai, Daniel Chiș</p>
                <p>This application was developed by students from University POLITEHNICA Bucharest / Automatic Control and 
                    Computer Science Faculty within the Erasmus Project: 2023-1-RO01- KA220-HED-000154433.
                </p>
                <br></br>
                <p>Students involved in the development of the application: Alexandru
                    Călăraș, Andrei-Beniamin Ciobănașu, Gabriel-Alexandru Indrei, Vladimir Jitaru,
                    Vlad-Ovidiu Măgureanu</p>
            </div>
            <Link to="/">
                <button>Back to Main Page</button>
            </Link>
        </div>
    );
}

export default Credentials;