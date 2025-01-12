# API Reference

This document describes the APIs exposed by the system for interacting with various components.

## Authentication API
### `POST /auth/login`
- **Description:** Authenticates a user and provides a token.
- **Request:**
  ```json
  {
    "username": "string",
    "password": "string"
  }
