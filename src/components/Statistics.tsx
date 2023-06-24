// Component for the Statistics section of the Home page
//

// Two components: one for the statistics section,
//  and one for a statistic

import React from 'react';
import {useMemo, useState, useEffect} from 'react';

// import { Statistic } from './Statistic';

import './Statistics.css';

type StatisticProps = {
    name: string;
    value: string;
}

const Statistic = (props: StatisticProps) => {
    return (
        <div className="statistic">
            <div className="stat-number">{props.value}</div>
            <div className="stat-name">{props.name}</div>
        </div>
    );
}

export interface IStatistics{
    settings_number: string;
    books_number: string;
    pages_number: string;
    unique_number: string;
}

export const StatisticBlock = () => {
    // Fetch data from the API
    const [data, setData] = React.useState<any>(null);
    useEffect(() => {
        let active = true
        loadStatistics()
        return () => { active = false }

        async function loadStatistics() {
            // const response = await DataService.getStatistics();
            if (active) {
                // setData(response);
            }
        }
    }, []);
    console.log(data)
    // if data is not null and has members, render the statistics
    var settings_number
    var books_number
    var pages_number
    var unique_number;
    // if (data === null){
        settings_number = data === null ? "..." : Number(data[0]["stat_value"]).toLocaleString('en', {useGrouping: true});
        books_number = data == null ? "..." : Number(data[1]["stat_value"]).toLocaleString('en', {useGrouping: true});
        pages_number = data == null ? "..." : Number(data[2]["stat_value"]).toLocaleString('en', {useGrouping: true});
        unique_number = data == null ? "..." : Number(data[3]["stat_value"]).toLocaleString('en', {useGrouping: true});
    // }
    // if (data && data.settings_number
    //     && data.books_number
    //     && data.pages_number
    //     && data.unique_number) {
    //         var settings_number = data === null ? "..." : Number(data[0]["stat_value"]).toLocaleString('en', {useGrouping: true});
    //         var books_number = data == null ? "..." : Number(data[1]["stat_value"]).toLocaleString('en', {useGrouping: true});
    //         var pages_number = data == null ? "..." : Number(data[2]["stat_value"]).toLocaleString('en', {useGrouping: true});
    //         var unique_number = data == null ? "..." : Number(data[3]["stat_value"]).toLocaleString('en', {useGrouping: true});
    //     }



    return (
        <div className="statistics">
            <div className="statistics_container">
            <div className="statistics_header">
                <h1>Statistics</h1>
                </div>
                <div className="statistics_grid">
                    <Statistic
                        name="Settings"
                        value={settings_number}
                    />
                    <Statistic
                        name="Books"
                        // value={books_number.toLocaleString('en', {useGrouping: true})}
                        value={books_number}
                    />
                    <Statistic
                        name="Monster Pages"
                        value={pages_number}
                    />
                    <Statistic
                        name="Unique Monsters"
                        value={unique_number}
                    />
                </div>
            </div>
        </div>
    );
    }