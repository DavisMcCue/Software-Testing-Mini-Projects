import unittest
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import Select
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions

class selenium_test_examples(unittest.TestCase):

    def setUp(self):
        self.browser = webdriver.Chrome()
        self.browser.get('file:///Users/mdecker/teaching/mdecker_courses/software_testing/lectures/selenium/test.html')

    def test_title(self):
        self.assertEqual('Test file for Selenium', self.browser.title)

    def test_select(self):

        element = self.browser.find_element_by_xpath("//select[@name='movie']")

        ## Could do
        # all_options = element.find_elements_by_tag_name("option")
        # for option in all_options:
        #     print("Value is: %s" % option.get_attribute("value"))
        # option.click()
        select = Select(element)
        select.select_by_value('spaceballs')

        self.assertEqual(len(select.all_selected_options), 1)
        self.assertEqual(select.all_selected_options[0].get_attribute("value"), "spaceballs")

    def test_wait(self) :
        self.browser.get('https://www.cs.bgsu.edu/mdecke/classes/software_testing/')

        # self.browser.implicitly_wait(10)
        # element = WebDriverWait(self.browser, 10).until(
        #     expected_conditions.presence_of_element_located((By.XPATH, "//h6"))
        # )

        self.assertEqual('Software Testing and Quality Assurance', self.browser.title)

        self.assertTrue(len(self.browser.find_elements_by_xpath('//h6')) > 0)

    def tearDown(self):
        self.browser.close()

if __name__ == "__main__":
    unittest.main()