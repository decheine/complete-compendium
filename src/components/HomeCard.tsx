// Component HomeCard

import React from 'react';

import './HomeCard.css';

type HomeCardProps = {
    title: string,
    body: string,
    linkText: string,
    link: string
}

export function HomeCard(props: HomeCardProps) {
    return (
        <div className="HomeCard">
                <div className="card-frame">
                    <div className="flex-top">
                        <div className="card-title">{props.title}</div>
                        <div className="card-body">{props.body}</div>
                    </div>

                        <div className="card-link">
                            <a href={props.link}>
                            {props.linkText}
                            </a>
                        </div>
                </div>
        </div>
    );
}