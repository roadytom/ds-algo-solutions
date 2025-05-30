from collections import defaultdict
from datetime import datetime

import pandas as pd

# Read Excel file
file_path = '2025-04-15 Yugo Meter Start End Dates.xlsx'  # Replace with your Excel file path
df = pd.read_excel(file_path)

# Specify the column you want to read (e.g., 'Account')
account_number = 'Account'
account_start_date = 'ACCOUNT OPENED'
account_end_date = 'ACCOUNT CLOSED'


def normalize_date(value):
    if pd.isna(value):
        return ""
    if isinstance(value, str) and value.strip().upper() == "OPEN":
        return ""
    if isinstance(value, datetime):
        return value.strftime('%m/%d/%Y')
    try:
        # Try parsing if it's a string date like '1/2/2023'
        parsed = pd.to_datetime(value)
        return parsed.strftime('%m/%d/%Y')
    except Exception:
        return ""


def get_earlier_date(date_str1, date_str2):
    format_str = "%m/%d/%Y"

    # Handle empty strings
    if date_str1 == "" and date_str2 == "":
        return ""
    if date_str1 == "":
        return date_str2
    if date_str2 == "":
        return date_str1

    # Parse and compare
    date1 = datetime.strptime(date_str1, format_str)
    date2 = datetime.strptime(date_str2, format_str)
    earlier_date = min(date1, date2)

    return earlier_date.strftime(format_str)


def get_later_date(date_str1, date_str2):
    format_str = "%m/%d/%Y"

    # Handle empty strings
    if date_str1 == "" and date_str2 == "":
        return ""
    if date_str1 == "":
        return date_str2
    if date_str2 == "":
        return date_str1

    # Parse and compare
    date1 = datetime.strptime(date_str1, format_str)
    date2 = datetime.strptime(date_str2, format_str)
    earlier_date = max(date1, date2)

    return earlier_date.strftime(format_str)


df[account_start_date] = df[account_start_date].apply(normalize_date)
df[account_end_date] = df[account_end_date].apply(normalize_date)
dictionary = defaultdict(lambda: ("", ""))
# Print each value in the column on a separate line
for index, row in df.iterrows():
    row_account_number = "" if pd.isna(row[account_number]) else str(row[account_number]).strip()
    if row_account_number == '':
        continue
    row_account_start_date = "" if pd.isna(row[account_start_date]) else str(row[account_start_date]).strip()
    row_account_end_date = "" if pd.isna(row[account_end_date]) else str(row[account_end_date]).strip()
    prev_dates = dictionary[row_account_number]
    dictionary[row_account_number] = (
        get_earlier_date(prev_dates[0], row_account_start_date), get_later_date(prev_dates[1], row_account_end_date))

for account_number, (start_date, end_date) in dictionary.items():
    print(f"('{account_number}', '{start_date}', '{end_date}'),")
print(len(dictionary))
