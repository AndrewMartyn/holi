<script lang="ts">
	import { onMount, onDestroy } from 'svelte';

	let socket: WebSocket | null = null;
	let messages: string[] = [];
	let message: string = '';

	onMount(() => {
    socket = new WebSocket("ws://127.0.0.1");

    socket.onopen = () => {
      console.log("Websocket connection established");
    };

    socket.onmessage = (event) => {
      const data: string = event.data;
      console.log("Message from server:", data);
      messages = [...messages, data];
    };

    socket.onerror = (error: Event) => {
      console.error("WebSocket error:", error);
    };

    socket.onclose = () => {
      console.log("WebSocket connection closed");
    };
  });

  export function sendMessage() {
    if (message && socket && socket.readyState === WebSocket.OPEN) {
      socket.send(message);
      message = ""; // Clear input after sending
    } else {
      console.log("WebSocket is not open or message is empty");
    }
  }

  onDestroy(() => {
    if (socket) {
      socket.close();
    }
  });
</script>
