#!/usr/bin/env python3
import os
import shutil

def find_targets(root="."):
    """Find files without extension and folders ending with .dSYM in root folder."""
    targets = []
    for entry in os.listdir(root):
        path = os.path.join(root, entry)

        # Case 1: folders ending with .dSYM
        if os.path.isdir(path) and entry.endswith(".dSYM"):
            targets.append(path)

        # Case 2: files without extension
        elif os.path.isfile(path) and "." not in entry:
            targets.append(path)

    return targets

def clean_root(root="."):
    targets = find_targets(root)

    if not targets:
        print("         ✅ No files or folders to delete.")
        return

    print("         ⚠️ The following items will be deleted:")
    for t in targets:
        print("   ", t)

    choice = input("\nProceed with deletion? (y/N): ").strip().lower()
    if choice != "y":
        print("         ❌ Aborted.")
        return

    for t in targets:
        if os.path.isdir(t):
            shutil.rmtree(t)
            print(f"Deleted folder: {t}")
        else:
            os.remove(t)
            print(f"Deleted file: {t}")

    print("✅ Cleanup complete.")

if __name__ == "__main__":
    clean_root(".")