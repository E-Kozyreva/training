from newspaper import Article
import textwrap


def parser():

  # Get the page link for parsing
  url = input('Enter the page link for parsing: ')

  # Creating an object for parsing the article
  article = Article(url)

  # Uploading the article
  article.download()

  # Article parsing
  article.parse()

  # Display the title of the article
  title_of_article = article.title
  print('\n{0}\n'.format(title_of_article.upper()))

  parsing_text = article.text

  # Output of brief information about the article
  text = textwrap.dedent(parsing_text).strip()
  for width in [50]:
    print(textwrap.fill(text, width=width))
    print()


parser()
