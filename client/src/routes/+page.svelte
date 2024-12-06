<script>
  import WebSocket from '$lib/WebSocket.svelte';

	let count = $state(0);

	function increment() {
		count += 1;
	}
</script>

<h1 class="bg-slate-200">Tsddsd</h1>
<button class="" onclick={increment}>
	count: {count}
</button>
