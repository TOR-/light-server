<h1>light-server</h1>
<div>
  <h2>Objectives</h2>
  <ul>
    <li>Get TCP sockets layer running (listen on port/ports, accept client connections and send/receive data).</li>
    <li>Implement a buffered reader so that you can read requests one line (delimited by CRLF) at a time.</li>
    <li>Read the very first line. Parse out the method, the request version and the path.</li>
    <li>Implement header parsing for the "Header: value" syntax. Don't forget unfolding folded headers.</li>
    <li>Check the request method, content type and content size to determine how/if the body will be read.</li>
    <li>Implement decoding of content based on content type.</li>
    <li>If supporting HTTP 1.1, implement things like "100 Continue", keep-alive, chunked transfer.</li>
    <li>Add robustness/security measures like detecting incomplete requests, limiting max number of clients etc.</li>
  </ul>
</div>
