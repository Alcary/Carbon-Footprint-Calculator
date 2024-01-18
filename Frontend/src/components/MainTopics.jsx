import MainTopic from './MainTopic'
import { MAIN_TOPICS } from './topicData'

export default function MainTopics(){
    return (
        <section id="main-topics">
            <ul>
                {MAIN_TOPICS.map((conceptItem) => (
                    <MainTopic key={conceptItem.title} {...conceptItem}/>
                ))}
            </ul>
        </section>
    );
}