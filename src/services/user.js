import axios from 'axios';

export default {
  testRequest() {
    return axios.get('api/test');
  },
};
