import wikipedia
import textwrap

generalizing_word_of_user = input('Enter a generalizing word to search for the article: ')

# Checking for the correctness of the input and searching for the article
generalizing_word = wikipedia.suggest(generalizing_word_of_user)

if generalizing_word is not None:
    print('Perhaps you meant {0}? We were able to find such articles for your query'.format(generalizing_word))
    print('\nSelect one of them:\n')

    possible_articles_1 = list(wikipedia.search(generalizing_word))

    # Output of the found articles
    number_of_article = 1
    for page in possible_articles_1:
        print('{0} | Title | {1}'.format(number_of_article, page))
        number_of_article += 1

    article_number = int(input('\nEnter the number of the article you are interested in: '))

    # Getting a page
    python_page = wikipedia.page(possible_articles_1[article_number-1])

    # URL of the page
    page_url = python_page.url

    # Original title
    original_page_title = python_page.original_title

    # Summary
    page_summary = str(python_page.summary)

    # Output of the page code and original title
    print('''\nORIGINAL TITLE: {0}\nURL: {1}\n'''.format(
        original_page_title, page_url))

    # Output of brief information about the article
    summary = textwrap.dedent(page_summary).strip()
    for width in [100]:
        print(textwrap.fill(summary, width=width))
        print()
else:
    possible_articles_2 = list(wikipedia.search(generalizing_word_of_user))
    print("\nHere's what I managed to find:\n")

    # Output of the found articles
    number_of_article = 1
    for page in possible_articles_2:
        print('{0} | Title | {1}'.format(number_of_article, page))
        number_of_article += 1

    article_number = int(input('\nEnter the number of the article you are interested in: '))

    # Getting a page
    python_page = wikipedia.page(possible_articles_2[article_number-1])

    # URL of the page
    page_url = python_page.url

    # Original title
    original_page_title = python_page.original_title

    # Summary
    page_summary = str(python_page.summary)

    # Output of the page code and original title
    print('''\nORIGINAL TITLE: {0}\nURL: {1}\n'''.format(
          original_page_title, page_url))

    # Output of brief information about the article
    summary = textwrap.dedent(page_summary).strip()
    for width in [100]:
        print(textwrap.fill(summary, width=width))
        print()
    
