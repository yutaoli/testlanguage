<template>
  <div id="app">
<!--     <img src="./assets/logo.png"> -->
    <SimpleGrid />
  </div>
</template>

<script>
import SimpleGrid from './components/SimpleGrid'

export default {
  name: 'App',
  components: {
    SimpleGrid
  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
