import React from "react"

import { useEffect, useRef, useState } from "react";


const useIntersectionObserver = (setActiveId: React.Dispatch<React.SetStateAction<string>>) => {
  const headingElementsRef = useRef<Map<string, any>|null>(null);

  useEffect(() => {
    const callback = (headings: Array<any>) => {
      headingElementsRef.current = headings.reduce((map: Map<string, any>, headingElement) => {
        if (!map) {
          map = new Map();
        } else {
          map.set(headingElement.target.id, headingElement);
        }
        return map;
      }, headingElementsRef.current);

      

      const visibleHeadings: any[] = [];
      // console.log(visibleHeadings);
      if(!headingElementsRef.current) {
        // console.log("no headings");
      } else {
        headingElementsRef.current.forEach((value: any, key: any) => {
          // console.log("key: ", key);
          if(headingElementsRef.current != null){
            if(value != null && value.isIntersecting) {
              const headingElement = value;
            if (headingElement.isIntersecting) 
              visibleHeadings.push(headingElement);
          }
        }
      });

      const getIndexFromId = (id: string) =>
        headingElements.findIndex((heading) => heading.id === id);
      
      if (visibleHeadings.length === 1) {
        setActiveId(visibleHeadings[0].target.id);
      } else if (visibleHeadings.length > 1) {
        const sortedVisibleHeadings = visibleHeadings.sort(
          (a: any, b: any) => getIndexFromId(a.target.id) - getIndexFromId(b.target.id)
        );
        setActiveId(sortedVisibleHeadings[0].target.id);
      }
      }
    }

    const observer = new IntersectionObserver(callback, {
      rootMargin: '0px 0px 0px 0px',
    });

    const headingElements = Array.from(document.querySelectorAll("h2, h3"));
    headingElements.forEach((element) => observer.observe(element));


    
    return () => observer.disconnect();
  }, [setActiveId]);
};


const Headings = (props: { headings: Array<any>, activeId: string|any }) => (
  <ul>
    {
    props.headings.map((heading: any) => (
      <li key={heading.id} className={heading.id === props.activeId ? "active" : "inactive"}>
      
      <div className="toc-entry-wrapper">
      <div className="bullet"></div>
      <a
          href={`#${heading.id}`}
          onClick={(e) => {
            e.preventDefault();
            document.querySelector(`#${heading.id}`)!.scrollIntoView({
              behavior: "smooth"
            });
          }}
        >{heading.title}</a>
        </div>
        {heading.items.length > 0 && (
          <ul>
            {heading.items.map((child: any) => (
              <li key={child.id} className={child.id === props.activeId ? "active" : "inactive"}>
              <div className="toc-entry-wrapper">
              <div className="bullet"></div>
              <a
                  href={`#${child.id}`}
                  onClick={(e) => {
                    e.preventDefault();
                    document.querySelector(`#${child.id}`)!.scrollIntoView({
                      behavior: "smooth"
                    });
                  }}
                >{child.title}</a>
                </div>
              </li>
            ))}
          </ul>
        )}
        
      </li>
    ))}
  </ul>
);

const TableOfContents = () => {
  const [activeId, setActiveId] = useState<string>("");
  const { nestedHeadings } = useHeadingsData();
  useIntersectionObserver(setActiveId);

  return (
    <nav className="toc" aria-label="Table of contents">
      <Headings headings={nestedHeadings} activeId={activeId}/>
    </nav>
  );
};


const getNestedHeadings = (headingElements: Element[]) => {
  const nestedHeadings: { id: any; title: any; items: Array<any>; }[] = [];

  headingElements.forEach((heading: any, index: any) => {
    const { innerText: title, id } = heading;
    // console.log("title: " + title)
    if (heading.nodeName === "H2") {
      nestedHeadings.push({ id, title, items: [] });
    } else if (heading.nodeName === "H3" && nestedHeadings.length > 0) {
      nestedHeadings[nestedHeadings.length - 1].items.push({
        id,
        title,
      });
    }
  });
  // console.log(nestedHeadings)

  return nestedHeadings;
};

// interface StateProperties {
//   nestedHeadings: { id: any; title: any; items: Array<any>; }[];
//   // age: number;
// }


const useHeadingsData = () => {
  const [nestedHeadings, setNestedHeadings] = useState<Array<{ id: any; title: any; items: Array<any>; }>>([]);

  useEffect(() => {
    const headingElements = Array.from(
      document.querySelectorAll("h2, h3")
    );

    const newNestedHeadings = getNestedHeadings(headingElements);
    setNestedHeadings(newNestedHeadings);
  }, []);

  return { nestedHeadings };
};


// const TableOfContents = () => {
//     return (
//         <nav className="toc" aria-label="Table of contents">
//             Hello world!
//         </nav>
//     );
// };

export default TableOfContents;