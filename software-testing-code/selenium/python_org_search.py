import unittest
from selenium import webdriver
from selenium.webdriver.common.keys import Keys

class python_org_search(unittest.TestCase):

    def setUp(self):
        self.browser = webdriver.Chrome()

    def test_search_box(self):
        self.browser.get("http://www.python.org")
        self.assertIn("Python", self.browser.title)
        elem = self.browser.find_element_by_name("q")
        elem.send_keys("argparse")
        elem.send_keys(Keys.RETURN)
        assert "No results found." not in self.browser.page_source


    def tearDown(self):
        self.browser.close()

if __name__ == "__main__":
    unittest.main()