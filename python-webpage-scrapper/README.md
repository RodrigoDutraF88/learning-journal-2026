So i will read an article from freeCodeCamp: How to Build Your Own Web Scraper (Article): A complete step-by-step written guide mapping out how to parse page text, loop through pagination parameters, and export your structured findings into a CSV file using pandas or python's default CSV handlers

And I'll document the things i learn in this process,

## WHAT I LEARNED

- Python Requests library is responsible for fetching HTML content from the URL you provide in the script. Once it retrieves the content, it stores the data in a response object.
-Beautiful Soup then takes over transforming the raw HTML from the Request response into a structured format and parsing it. then you can scrape data fro the parsed HTML 
- This has two limitations, The Request library can't handle websites with dynamic JavaScript content. If you need to scrape a dynamically loaded site, you will have to use more advanced automation tools like Selenium.
-the code i'll write below will go through each dataset, scrape the details, and save them to a CSV file.
-download beautifulsoup and request libraries: pip install requests
pip install beautifulsoup4
- 

