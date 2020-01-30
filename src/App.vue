<template>
  <v-app>
    <Header />
    <router-view />
    <Footer />
  </v-app>
</template>

<script>
// import components
import Header from './components/base/Header';
import Footer from './components/base/Footer';

export default {
  name: 'App',
  components: {
    Header,
    Footer,
  },
};
</script>
