import logging

logging.basicConfig(level=logging.DEBUG, filename="logs.log", filemode="w", format="We have next logging: %(asctime)s:%(levelname)s-%(message)s")

logging.debug("DEBUG")
logging.info("INFO")
logging.warning("WARNING")
logging.error("ERROR")
logging.critical("CRITICAL")

try:
    print(10/0)
except:
    logging.exception("Exception")

assert 2+2 == 5, "wrong assert"

"""
>>> 2+2
5
"""

if __name__ == "__main__":
    import doctest
    doctest.testmod()