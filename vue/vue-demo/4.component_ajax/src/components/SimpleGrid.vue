<template id="grid-template">
  <table>
    <thead>
      <tr>
        <th v-for="col in gridColumns" :key="col">
          {{ col }}
        </th>
      </tr>
    </thead>
    <tbody>
      <tr v-for="entry in gridData" :key="entry.Name">
        <!-- <td v-for="col in columns">
                        {{entry[col]}}
                    </td> -->
        <td>{{ entry.Name }}</td>
        <td>{{ entry.Age }}</td>
        <td>{{ entry.Sex }}</td>
      </tr>
    </tbody>
  </table>
</template>

 <script>
import axios from "axios";

export default {
  name: "SimpleGrid",
  // el: "#grid-template",
  data() {
    return {
      searchQuery: "",
      gridColumns: ["name", "age", "sex"],
      gridData: [],
      apiUrl: "/test/getGridData",
    };
  },
  mounted() {
    console.log(this.apiUrl);
    this.getGridData();
    
  },
  methods: {
    getGridData: function () {
      console.log(this.apiUrl);
      axios
      .get(this.apiUrl)
      .then((res) => {
        console.log(res)
        this.gridData = res.data.Data;
        console.log(this.gridData);
      })
      .catch((error) => {
        console.log(error);
        // Manage errors if found any
      });
    },
  },
};
</script>