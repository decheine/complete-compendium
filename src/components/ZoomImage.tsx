// React component that displays an image and if the user clicks on it, it will zoom in on the image
import React from 'react';

import './ZoomImage.css';

// const ZoomImage = (props: any) => {
//     const [zoomed, setZoomed] = useState(false);

//     const zoomImage = () => {
//         setZoomed(!zoomed);
//     }

//     return (
//         <div className="ZoomImage">
//             <img src={props.src} alt={props.alt} onClick={zoomImage} className={zoomed ? "zoomed" : "regular"}/>
//         </div>
//     );
// }

type ZoomImageProps = {
    src: string,
    alt: string
};
class ZoomImage extends React.Component<ZoomImageProps>{
    constructor(props: ZoomImageProps){
        super(props);
        this.state = {
            zoomed: false,
        }
        this.zoomDone = this.zoomDone.bind(this);
    }
    componentDidMount() {
        // const elm = this.image;
        // elm.addEventListener("animationend", this.zoomDone);
    }

    componentWillUnmount() {
        // const elm = this.image;
        // elm.removeEventListener("animationend", this.zoomDone);
    }

    zoomIn(){
        this.setState({ zoomed: true})
    }
    zoomOut(){
        this.setState({ zoomed: false})
    }


    zoomDone() {
        this.setState( function(state: any, props: any) {
            return {
                zoomed: !state.zoomed,
            }
        }
        );
        
    }

    render(){
        const {zoomed} = (this.state as any);
        return (
            // Base im age
            <>
            <div className="RegularImage">
                <img 
                        src={this.props.src} 
                        alt={this.props.alt} 
                        ref={elm => {
                            // this.image = elm;
                        }}
                        onClick={() => {this.setState({zoomed: !(this.state as any).zoomed}); console.log("clicked", this.state)}}
                        className="regular"
                    />
            </div>
            {zoomed ? 
             <div className="overlay" onClick={() => {this.setState({zoomed: !(this.state as any).zoomed}); console.log("clicked", this.state)}}>
                <img 
                    src={this.props.src} 
                    alt={this.props.alt} 
                    ref={elm => {
                        // this.image = elm;
                    }}
                    onClick={() => {this.setState({zoomed: !(this.state as any).zoomed}); console.log("clicked", this.state)}}
                    className={zoomed ? "zoomed" : "regular"}
                />
            </div>
                : null
            }
            
            </>
        )
    }
}

export default ZoomImage;